// Room: /yangzhou/baitabaosha.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","白塔宝刹");
	set("long",@LONG
圆锥形白塔宝刹，由佛教十三层相轮组成，层级高二丈，径丈许，
刹端置六角形宝盖，角端悬挂风铃，每当风起，铃声阵阵。宝盖为青铜
缨络，上托鎏金黄铜中空葫芦形宝顶，宝顶高丈许。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"down" : __DIR__"baitafokan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 50);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}