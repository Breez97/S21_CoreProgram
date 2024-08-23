INSERT INTO person_visits
VALUES
	(
		(SELECT MAX(id) FROM person_visits) + 1,
		(SELECT id FROM person WHERE name = 'Dmitriy'),
		(SELECT pz.id FROM pizzeria pz
				JOIN menu mn ON mn.pizzeria_id = pz.id
			WHERE pz.name != (
					SELECT pizzeria_name
					FROM mv_dmitriy_visits_and_eats
				)
				AND price < 800
			LIMIT 1
		), 
		TIMESTAMP '2022-01-08'
	);

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;