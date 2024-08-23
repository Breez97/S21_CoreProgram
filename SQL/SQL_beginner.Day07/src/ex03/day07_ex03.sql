WITH visits AS (
	SELECT 
		pz.name AS name, 
		COUNT(pv.*) AS count
	FROM person_visits pv
	JOIN pizzeria pz ON pz.id = pv.pizzeria_id
	GROUP BY pz.name
),
orders AS (
	SELECT
		pz.name AS name,
		COUNT(po.*) AS count
	FROM person_order po
	JOIN menu mn ON mn.id = po.menu_id
	JOIN pizzeria pz ON pz.id = mn.pizzeria_id
	GROUP BY pz.name
),
visits_and_orders AS (
	SELECT * FROM visits
	UNION ALL
	SELECT * FROM orders
)

SELECT name, SUM(count) AS total_count FROM visits_and_orders
GROUP BY name
ORDER BY total_count DESC, name;