// Room: /d/taishan/hutiange.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "壶天阁");
	set("long", @LONG
壶天阁名取自道家以壶天为仙境之意。明代称升仙阁，清乾隆皇帝
登岱时拓建改今名。阁为跨道门楼式建筑，清嘉庆年间崔映辰题联：“
壶天日月开灵境，盘路风云入翠微。”廷璐又联：“登此山一半已是壶
天，造极顶千重尚多福地。”门洞有双柏自墙中横生，盘旋而上，堪称
奇景。
LONG );
	set("exits", ([
		"westup"    : __DIR__"huima",
		"southdown" : __DIR__"sihuaishu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 650);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
