// ROOM xuanbing1.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "玄兵古洞");
	set("long", @LONG
这里是玄兵古洞，四面洞壁之上结满了石英的柱状结晶体，显得十
分漂亮。前方一个巨大的炉子前站着一位长髯老者正看着炉火想着什么
心事，旁边几个彪形大汉正挥舞着锤头敲打着一块似乎总也烧不红的什
么金属。旁边仔细的放着几把刚刚出炉的兵器。那种骇人的杀气竟是从
这些兵器上散发出来的。
LONG );
	set("exits", ([
		"out" : __DIR__"xuanbing",
	]));
	set("objects" , ([
		__DIR__"npc/ouyezi" : 1,
	]) );
	set("coor/x", -41200);
	set("coor/y", 8980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
