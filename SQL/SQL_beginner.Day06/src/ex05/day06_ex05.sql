COMMENT ON TABLE person_discounts IS 'This table contains information about personal discounts for different people in pizzerias';
COMMENT ON COLUMN person_discounts.id IS 'Column contains ID (Primary Key) for table person_discounts';
COMMENT ON COLUMN person_discounts.person_id IS 'Column contains person identifiers (Foreign Key) for dependency with person table';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Column contains pizzerias identifiers (Foreign Key) for dependency with pizzeria table';
COMMENT ON COLUMN person_discounts.discount IS 'Column contains contains amount of discount for certain person';