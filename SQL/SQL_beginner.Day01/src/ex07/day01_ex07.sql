SELECT po.order_date AS order_date, CONCAT(pr.name, ' (age:', pr.age, ')') AS person_information FROM person_order AS po
JOIN person AS pr ON pr.id = po.person_id
ORDER BY order_date, person_information;