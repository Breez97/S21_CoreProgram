CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit() RETURNS TRIGGER AS $trg_person_delete_audit$
BEGIN
	IF (TG_OP = 'DELETE') THEN
		INSERT INTO person_audit SELECT CURRENT_TIMESTAMP, 'D', OLD.*;
		RETURN OLD;
	END IF;
	RETURN NULL;
END;
$trg_person_delete_audit$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_delete_audit
	AFTER DELETE on person
	FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_delete_audit();

DELETE FROM person WHERE id = 10;