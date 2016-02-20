//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "城陵矶");
	set ("long", @LONG
这里是洞庭湖与长江汇合处，水天浩淼，茫茫荡荡。几只鸥鸟拍打
着翅膀不时从水面横掠而过。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"dangyangqiao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
