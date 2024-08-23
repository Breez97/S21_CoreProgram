CREATE SEQUENCE IF NOT EXISTS seq_person_discounts START WITH 1;
ALTER TABLE person_discounts 
	ALTER COLUMN id SET default nextval('seq_person_discounts');
SELECT setval('seq_person_discounts', (SELECT COUNT(*) + 1 FROM person_discounts));