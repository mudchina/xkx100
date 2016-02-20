// Room: /d/wuxi/wuguanwoshi.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这是秦教头的卧室，由于秦教头门下弟子众多，秦教头手头也颇为
宽绰，房里布置得自然是相当华丽。红木大床上铺着锦缎花被，云丝罗
帐低垂，屋角燃着檀香，显得十分安静。
LONG );
	set("exits", ([
		"west" : __DIR__"wuchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}