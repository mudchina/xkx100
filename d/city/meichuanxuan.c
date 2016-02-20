// Room: /yangzhou/meichuanxuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "梅船轩");
	set("long", @LONG
中央有厅三楹，南向明间廊柱上，悬一幅楹联(lian)。在厅的四周
地坪上，以鹅卵石与瓦片铺地，纹作“水波粼粼”状。给人一水的意境。
厅的四壁，皆是明窗，人在其中，可以作四面观。厅的东南，有老槐荫
蔽，山石少许，点缀其间。厅的东北，以湖石贴墙作山，山势时起时伏，
逶迤而西。有石蹬可登。
LONG );
	set("outdoors", "yangzhouw");

	set("no_fight", 1);
	set("exits", ([
		"south"     : __DIR__"chuanlang",
		"northeast" : __DIR__"hushishanzi",
	]));
	set("objects", ([
		__DIR__"npc/yangwanxiao" : 1,
	]));
	set("item_desc", ([
		"lian" : @LONG
                  花         约
                  为         作
                  四         主
                  壁         人
                  船         梅
                  为         作
                  家         客
LONG,
	]));
	set("coor/x", -11);
	set("coor/y", -48);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}