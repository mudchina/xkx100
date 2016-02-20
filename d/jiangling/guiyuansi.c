//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "归元寺");
	set ("long", @LONG
一座清幽禅院。据说寺中藏有印度、斯里兰卡、缅甸、泰国、日本
等国相赠的佛经，还有橡木韦驮雕像、白玉佛像、五百罗汉像和千手观
音像等宝物。
LONG);
	set("exits", ([
		"west" : __DIR__"hzjie5",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
