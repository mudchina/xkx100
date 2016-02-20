//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "书房");
	set ("long", @LONG
这是万老爷子的书房。摆设简单整洁。左首一堵白墙特别惹眼。
LONG);
	set("exits", ([
		"west" : __DIR__"beilou",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}