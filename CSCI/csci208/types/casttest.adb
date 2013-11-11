with Ada.Float_Text_IO;
use Ada.Float_Text_IO;

procedure CastTest is

  x : Integer := 1;
  y : Float := 3.0;

begin

  y := Float(x);
  x := Integer(y);
  put(x);

end CastTest;
