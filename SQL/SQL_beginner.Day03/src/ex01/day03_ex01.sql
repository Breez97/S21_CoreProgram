SELECT mn.id AS menu_id
FROM menu mn
WHERE mn.id NOT IN (SELECT po.menu_id FROM person_order po)
ORDER BY menu_id;