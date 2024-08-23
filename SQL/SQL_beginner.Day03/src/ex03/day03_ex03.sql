WITH all_genders AS (
	SELECT
		pz.name AS pizzeria_name,
		ps.gender AS gender
	FROM
		person_visits pv
		JOIN person ps ON ps.id = pv.person_id
		JOIN pizzeria pz ON pz.id = pv.pizzeria_id
),
men AS (SELECT pizzeria_name FROM all_genders WHERE gender = 'male'),
women AS (SELECT pizzeria_name FROM all_genders WHERE gender = 'female'),
only_men AS (
	SELECT * FROM men
	EXCEPT ALL
	SELECT * FROM women
),
only_women AS (
	SELECT * FROM women
	EXCEPT ALL
	SELECT * FROM men
)
SELECT * FROM only_men
UNION ALL
SELECT * FROM only_women
ORDER BY 1;