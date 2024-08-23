WITH new_orders AS (
	SELECT
		generate_series((SELECT MAX(id) FROM person_order) + 1, (SELECT MAX(id) FROM person_order) + (SELECT COUNT(*) FROM person)) AS id,
		generate_series((SELECT MIN(id) FROM person), (SELECT MAX(id) FROM person)) AS person_id,
		(SELECT id FROM menu WHERE pizza_name = 'greek pizza') AS menu_id,
		TO_DATE('2022-02-25', 'YYYY-MM-DD') AS order_date
)
INSERT INTO person_order
SELECT * FROM new_orders;