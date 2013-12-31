-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_hello" to load this file. \quit

CREATE OR REPLACE FUNCTION hello( TEXT ) RETURNS TEXT
  AS 'hello_world' LANGUAGE C;

