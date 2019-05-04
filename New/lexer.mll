(* File lexer.mll *)
{
open Parser        (* The type token is defined in parser.mli *)
exception Eof
}
(* Creating a lexing rule for the type token defined in parser *)
rule token = parse
    [' ' '\t' '\n']  { token lexbuf }  (* skip whitespace *)
  | ['.']            { EOL }    (* to demarcate end of each expression *)
  |'('               { LP }
  |')'               { RP }
  |','				 {COMMA}
  |':'				 {COLON}
  |'='				 {EQUAL}
  |"call"			 {CALL}
  |"ret"			 {RET}
  | ['-']?(['0'] | ['1'-'9']['0'-'9']*) as num_int 
                     { INT (int_of_string num_int)    }  (* Token for integer type *)
  | ['a'-'z']['a'-'z' 'A'-'Z' '0'-'9' '_']* as id_str 
                      { VAR (id_str) }  (* Token for variable string *)
  |['A'-'Z']['a'-'z' 'A'-'Z' '0'-'9' '_']* as name 
                      { FUNC (name) }
  | eof {EOF}
