// Room: /d/yanping/mingcuige.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "明翠阁");
	set("long", @LONG
明翠阁始建于南宋，初为观音阁。清康熙三十一年扩建，改称明翠
阁。它攀附于凤冠石的悬岩绝壁上，酷似空中楼阁，以险著称。参差错
落的木构建筑群，“廊腰漫回，檐牙高啄”，隔岸远观，像是一条腾空
盘旋的蟠龙，隐现于巍峨的山巅上和荟蔚的林木中。古诗云：“曲磴盘
空行，人语出林来”。阁内花红柳绿，风光旖旎。清代诗人朱宏作诗赞
颂：“四面八方皆入画，春花秋叶隔桥红。”
LONG );
	set("exits", ([
		"down" : __DIR__"fengguanyan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/shami" : 1,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
