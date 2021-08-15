SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id

WHERE people.name = "Johnny Depp" 

INTERSECT

SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id

WHERE people.name = "Helena Bonham Carter"

