// Room: /d/yueyang/liuyijing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "柳毅井");
	set("long", @LONG
柳毅井，亦称桔井。它位于君山龙口内的龙舌的根部。唐代李朝威
写的《柳毅传书》的故事 (story)，就发生在这里。井旁有古桔一株，
大“五六围”，枝干奇古。相传为柳传书之处。井入口丈许，有片石作
底，凿数孔以通泉，石下深不可测。古老相传，此井直通太湖。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("item_desc", ([
		"story" : "
    唐仪凤年间，书生柳毅赴京应考落第，归经泾阳，偶遇满脸泪痕的
牧羊女。柳毅上前询问得知，该女为洞庭龙女下嫁泾阳君，受其残暴虐
待至此。他受龙女之托，送信至君山，找到桔井，在井边的桔树上敲击
三下，守门的巡海神就将他接进了龙宫。见龙君，递上书信，又诉龙女
苦。龙君小弟钱塘君暴怒，作百丈赤龙，径往泾阳，灭泾阳君，接回龙
女，几经曲折招柳毅为婿的故事。\n"
	]));
	set("exits", ([
		"east"      : __DIR__"liuyiting",
		"southup"   : __DIR__"longsheshan",
		"northeast" : __DIR__"xiaolu5",
	]));
	set("coor/x", -1690);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
