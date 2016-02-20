//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "破祠堂");
	set ("long", @LONG
这是一个破败的祠堂。地下满是灰尘，桌椅都是甚是残破。
LONG);
	set("exits", ([
		"north" : __DIR__"huayuan",
	]));
	set("objects", ([
		__DIR__"npc/taohong" : 1,
	]));
  
	set("coor/x", -1486);
	set("coor/y", -2041);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
