// Room: /yangzhou/pingtai.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","平台石栏");
	set("long",@LONG
平台中二具铁镬，以太湖石为座，夏植荷花于镬内，成为绝大盆景。
铁镬直径六七尺，厚二寸，高与人肩齐，相传为萧梁时镇水之物。仪征
焦汝霖《铁镬记》碑石立于其侧。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northup" : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 39);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}