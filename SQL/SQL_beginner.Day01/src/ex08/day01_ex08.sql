SELECT po.order_date AS order_date, CONCAT(pr.name, ' (age:', pr.age, ')') AS person_information FROM person_order AS po
NATURAL JOIN (SELECT pr.id AS person_id, pr.name, pr.age FROM person AS pr) pr
ORDER BY order_date, person_information;