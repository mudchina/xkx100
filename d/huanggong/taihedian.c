// Room: /d/huanggong/taihedian.c
inherit ROOM;

void create()
{
	set("short", "太和殿");
	set("long", @LONG
这就是金銮宝殿. 朱红殿柱, 彩绘栋梁, 琉璃瓦顶, 在阳光之下, 
真是灿烂辉煌. 大殿正中的镂空精雕镏金龙椅, 不用说也知道就是九龙
宝座. 宝座周围是六根沥粉金漆的蟠龙柱, 御座前有造型美观的仙鹤和
炉鼎. 座后是精雕细刻的围屏. 每日皇在此上朝问政, 治理天下. 据说
这龙椅居于大地正中, 你尽可量量看.
LONG
	);
	set("exits", ([
		"north"     : __DIR__"zhonghedian",
		"south"     : __DIR__"taiji",
		"east"      : __DIR__"yongxiang3",
		"west"      : __DIR__"yongxiang2",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}