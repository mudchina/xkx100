// /d/shenlong/lin2.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
	set("short", "灌木林");
	set("long",@LONG
这是连片灌木林。周围安静得奇怪，让你觉得有一股莫名的恐惧伴
随着你。走了不远，你就可以看得见前面的空地了。
LONG);
	set("exits", ([
		"northdown" : __DIR__"kongdi",
		"southup"   : __DIR__"lin1",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
