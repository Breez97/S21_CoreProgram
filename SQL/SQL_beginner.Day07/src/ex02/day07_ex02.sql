WITH top_visits AS (
	SELECT
		pz.name AS name,
		COUNT(pv.*) AS count,
		'visit' AS action_type
	FROM person_visits pv
	JOIN pizzeria pz ON pz.id = pv.pizzeria_id
	GROUP BY pz.name
	ORDER BY count DESC
	LIMIT 3
),
top_orders AS (
	SELECT 
		pz.name AS name,
		COUNT(po.*) AS count,
		'order' AS action_type
	FROM person_order po
	JOIN menu mn ON mn.id = po.menu_id
	JOIN pizzeria pz ON pz.id = mn.pizzeria_id
	GROUP BY pz.name
	ORDER BY count DESC
	LIMIT 3
)

SELECT * FROM top_visits
UNION ALL
SELECT * FROM top_orders
ORDER BY action_type, count DESC;