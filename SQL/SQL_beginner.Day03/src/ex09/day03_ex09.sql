INSERT INTO person_visits
VALUES 
	((SELECT MAX(id) FROM person_visits) + 1,
	(SELECT id FROM person WHERE name = 'Denis'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'),
	TO_DATE('2022-02-24', 'YYYY-MM-DD')),

	((SELECT MAX(id) FROM person_visits) + 2,
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'),
	TO_DATE('2022-02-24', 'YYYY-MM-DD'));