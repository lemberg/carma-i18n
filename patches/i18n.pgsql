-- 
-- Table: 'i18n_node'
--

CREATE TABLE i18n_node (
  trid integer NOT NULL default '0',
  nid integer NOT NULL default '0',  
  status smallint NOT NULL default '0',
  PRIMARY KEY  (trid,nid)
);
CREATE SEQUENCE i18n_node_trid_seq INCREMENT 1 START 1;

-- Add language field to node table

ALTER TABLE node
ADD language char(2);
UPDATE node SET language='';
ALTER TABLE node ALTER COLUMN language SET NOT NULL;
ALTER TABLE node ALTER COLUMN language SET DEFAULT '';


-- Add language and trid fields to term_data
ALTER TABLE term_data ADD language char(2);
ALTER TABLE term_data ADD trid integer;

UPDATE term_data SET language='';
ALTER TABLE term_data ALTER COLUMN language SET NOT NULL;
ALTER TABLE term_data ALTER COLUMN language SET DEFAULT '';
UPDATE term_data SET trid='0';
ALTER TABLE term_data ALTER COLUMN trid SET NOT NULL;
ALTER TABLE term_data ALTER COLUMN trid SET DEFAULT '0';
