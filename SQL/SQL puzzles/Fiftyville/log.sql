-- Keep a log of any SQL queries you execute as you solve the mystery.
--INFO I KNOW:

--PSET SAYS TO CHECK CRIME SCENE REPORT FIRST
--DATE THE CRIME OCCURED: JULY 28TH.
--PLACE IT HAPPENED: CHAMBERLAIN ST.
--------------------------------------------------

SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Chamberlin Street";
--description text--
--Theft of the CS50 duck took place at 10:15am
--at the Chamberlin Street courthouse.
--Interviews were conducted today with three
--witnesses who were present at the time —
--each of their interview transcripts mentions
--the courthouse.
--check the interviews next maybe?
SELECT transcript FROM interviews
WHERE month = 7 AND day = 28
AND transcript LIKE "%courthouse%";

--Sometime within ten minutes of the theft,
--I saw the thief get into a car in the
--If you have security footage from the
--courthouse parking lot, you might want
--to look for cars that left the parking lot in that time frame.
--I don't know the thief's name, but it was someone
--I recognized. Earlier this morning, before I arrived
--at the courthouse, I was walking by the ATM on Fifer
--Street and saw the thief there withdrawing some money.
--As the thief was leaving the courthouse, they called
--someone who talked to them for less than a minute. I
--n the call, I heard the thief say that they were p
--lanning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the
--phone to purchase the flight ticket.

--maybe check the security tapes form the courthouse
SELECT name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE month = 7 AND day = 28
AND hour = 10 and minute >= 15
AND minute <= 25
AND activity = "exit";

--got a list of suspects :)
--name
--Patrick
--Ernest
--Amber
--Danielle
--Roger
--Elizabeth
--Russell
--Evelyn

-- if i cross reference this with
--the atm transactions, i might be able to get a bank account name
SELECT DISTINCT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE month = 7 AND day = 28
AND transaction_type = "withdraw"
AND atm_location = "Fifer Street";

--got another name list,so one of these people is the suspect
--Danielle
--Bobby
--Madison
--Ernest
--Roy
--Elizabeth
--Victoria
--Russell

--if i made sort of a venn diagrma of these
--2 lists, i need to comapre them and see whats common
--Specically I narrowed to
--Ernest, Russell, Danielle, Elizabeth
-- so i should be able to also figure out the flight
--and the accomplice from the phone call list from the 3rd text

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE month = 7 AND day = 29
ORDER by hour, minute LIMIT 1);

--this gives me a eprson list again--
--Doris
--Roger
--Ernest
--Edward
--Evelyn
--Madison
--Bobby
--Danielle

--So by comparing to the other list, the suspect is either Ernest OR Danielle
--If I check the phonecall next, it SHOULD show me the final criminal

SELECT DISTINCT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE month = 7 AND day = 28 AND duration <= 60;

--Finally we have a criminal, Ernest in on the list and Danielle isnt, so it's Ernest
--Roger
--Evelyn
--Ernest
--Kathryn
--Madison
--Russell
--Kimberly
--Bobby
--Victoria

--Next I can use the destination airport ID to get where Ernest escaped to

SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights WHERE month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1);

--from this, Ernest escaped to London

--Finally the next step is to determine Ernests accomplice
-- Use the phonecall receiver

SELECT name from people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE month = 7 AND day = 28 AND duration <= 60
AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");

--from this, the accomplice is Berthold