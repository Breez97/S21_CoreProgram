CREATE OR REPLACE VIEW v_price_with_discount AS
SELECT
	ps.name,
	mn.pizza_name,
	mn.price,
	(mn.price - mn.price * 0.1) :: int AS discount_price
FROM person_order po
	JOIN person ps ON ps.id = po.person_id
	JOIN menu mn ON mn.id = po.menu_id
ORDER BY
	ps.name,
	mn.pizza_name;