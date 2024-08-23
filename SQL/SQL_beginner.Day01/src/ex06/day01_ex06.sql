SELECT po.order_date AS action_date, (SELECT person.name FROM person WHERE person.id = po.person_id) AS person_name FROM person_order AS po
INTERSECT
SELECT pv.visit_date AS action_date, (SELECT person.name FROM person WHERE person.id = pv.person_id) AS person_name FROM person_visits AS pv
ORDER BY action_date, person_name DESC;