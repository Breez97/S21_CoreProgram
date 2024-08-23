SELECT po.person_id FROM person_order AS po
WHERE order_date = '2022-01-07'
EXCEPT ALL
SELECT pv.person_id FROM person_visits AS pv
WHERE visit_date = '2022-01-07';