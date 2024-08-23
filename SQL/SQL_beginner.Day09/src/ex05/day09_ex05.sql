DROP FUNCTION IF EXISTS fnc_persons_female();
DROP FUNCTION IF EXISTS fnc_persons_male();

CREATE OR REPLACE FUNCTION fnc_persons(IN pgender VARCHAR DEFAULT 'female')
	RETURNS TABLE (
		id BIGINT,
		name VARCHAR,
		age INTEGER,
		gender VARCHAR,
		address VARCHAR
	)
AS
$$
	SELECT * FROM person
	WHERE pgender = person.gender;
$$ LANGUAGE sql;

-- SELECT *
-- FROM fnc_persons(pgender := 'male');

-- SELECT *
-- FROM fnc_persons();