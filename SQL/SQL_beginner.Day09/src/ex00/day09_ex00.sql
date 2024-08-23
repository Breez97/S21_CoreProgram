CREATE TABLE IF NOT EXISTS person_audit (
	created TIMESTAMPTZ(0) DEFAULT CURRENT_TIMESTAMP NOT NULL,
	type_event CHAR(1) DEFAULT 'I' NOT NULL,
	CONSTRAINT ch_type_event CHECK (type_event IN ('I', 'U', 'D')),
	row_id BIGINT NOT NULL,
	name VARCHAR,
	age INTEGER,
	gender VARCHAR,
	address VARCHAR
);

CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit() RETURNS TRIGGER AS $trg_person_insert_audit$
BEGIN
	IF (TG_OP = 'INSERT') THEN
		INSERT INTO person_audit SELECT CURRENT_TIMESTAMP, 'I', NEW.*;
		RETURN NEW;
	END IF;
	RETURN NULL;
END;
$trg_person_insert_audit$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_insert_audit
	AFTER INSERT on person
	FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) 
VALUES (10, 'Damir', 22, 'male', 'Irkutsk');