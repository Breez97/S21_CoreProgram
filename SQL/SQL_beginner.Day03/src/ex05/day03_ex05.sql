WITH pizzeria_visits AS (
	SELECT
		DISTINCT pz.name AS pizzeria_name
	FROM
		person_visits pv
		JOIN pizzeria pz ON pz.id = pv.pizzeria_id
		JOIN person ps ON ps.id = pv.person_id
	WHERE ps.name = 'Andrey'
),
pizzeria_orders AS (
	SELECT DISTINCT pz.name AS pizzeria_name
	FROM
		person_order po
		JOIN person ps ON ps.id = po.person_id
		JOIN menu mn ON mn.id = po.menu_id
		JOIN pizzeria pz ON pz.id = mn.pizzeria_id
	WHERE ps.name = 'Andrey'
)
SELECT * FROM pizzeria_visits
EXCEPT
SELECT * FROM pizzeria_orders
ORDER BY 1;