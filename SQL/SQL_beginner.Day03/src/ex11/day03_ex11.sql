UPDATE menu
SET price = price * 0.9
WHERE id = (SELECT id FROM menu WHERE pizza_name = 'greek pizza');