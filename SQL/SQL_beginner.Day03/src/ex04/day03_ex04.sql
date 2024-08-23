WITH all_genders AS (
	SELECT
		pz.name AS pizzeria_name,
		ps.gender AS gender
	FROM
		person_order po
		JOIN person ps ON ps.id = po.person_id
		JOIN menu mn ON mn.id = po.menu_id
		JOIN pizzeria pz ON pz.id = mn.pizzeria_id
),
men AS (SELECT pizzeria_name FROM all_genders WHERE gender = 'male'),
women AS (SELECT pizzeria_name FROM all_genders WHERE gender = 'female'),
only_women AS (
	SELECT * FROM women 
	EXCEPT 
	SELECT * FROM men
),
only_men AS (
	SELECT * FROM men
	EXCEPT
	SELECT * FROM women
)
SELECT * FROM only_women
UNION
SELECT * FROM only_men
ORDER BY 1;