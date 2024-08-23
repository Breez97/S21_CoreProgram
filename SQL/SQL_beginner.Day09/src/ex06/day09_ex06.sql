CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(IN pperson VARCHAR DEFAULT 'Dmitriy', IN pprice INTEGER DEFAULT 500, IN pdate DATE DEFAULT '2022-01-08')
	RETURNS TABLE (name VARCHAR)
AS
$$
	SELECT pz.name FROM person_visits pv
	JOIN person ps ON ps.id = pv.person_id
	JOIN pizzeria pz ON pz.id = pv.pizzeria_id
	JOIN menu mn ON mn.pizzeria_id = pv.pizzeria_id
	WHERE ps.name = pperson AND mn.price < pprice AND pv.visit_date = pdate;
$$ LANGUAGE sql;

-- SELECT *
-- FROM fnc_person_visits_and_eats_on_date(pprice := 800);

-- SELECT *
-- FROM fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');
