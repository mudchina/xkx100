// /d/beihai/yuexin.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "悦心殿");
	set("long", @LONG
这里是永安寺西之悦心殿，殿内为五开间、西山灰瓦顶，是清帝引
见、理事之所。殿内非常安静，只依稀可闻有僧人扫着落叶的声音。殿
前有宽阔的月台，与庆宵楼相连殿内院中有一棵老树，枝叶茂密。殿内
光线很暗，看不清楚有些什么。
LONG
	);
	set("exits", ([
		"east"    : __DIR__"yongansi",
		"northup" : __DIR__"qingxiao",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
