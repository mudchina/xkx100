// Room: /d/heimuya/shenggu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM; 
void create()
{
	set("short", "圣姑堂");
	set("long",@LONG
这里便是黑木崖的圣姑所在地“圣姑堂”。堂上五彩云罗，煞是漂
亮。不过，圣姑对黑木崖俗务久已厌倦，一年之中倒有八九个月不在堂
中。
LONG );
	set("exits", ([
		"east" : __DIR__"chitang",
	]));
	set("objects", ([
//		CLASS_D("heimuya")+"/renyy" : 1,
		__DIR__"npc/shinu" : 2,
	]));       
//	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}