//Room: /d/dali/chahua2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花园");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园中，看万紫千红，争奇斗妍，心胸大爽。靠东一座小石凳，凳后柳
树成行，拖曳水面，把湖面点成一个个涟漪。
LONG);
	set("objects", ([
	   __DIR__"obj/chahua1": 1,
	   __DIR__"npc/huanu": 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"chahua1",
	    "northeast"  : __DIR__"chahua3",
	    "southeast"  : __DIR__"chahua4",
	]));
	set("coor/x", -38960);
	set("coor/y", -70000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}