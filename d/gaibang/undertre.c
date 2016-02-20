// Room: /d/gaibang/undertre.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "树洞下");
	set("long", @LONG
这是老槐树底部，四周光线昏暗，人影晃晃，似乎有几个黑暗的洞
口在你身边，通向四面八方。一位老乞丐大咧咧地坐在正中的地上。不
经意中你发现墙壁上画着幅粗糙的路线草图（map）。
LONG );
	set("no_fight", 1);
	set("exits", ([
		"up"   : __DIR__"inhole",
		"west" : __DIR__"chuchang",
		"0"    : __DIR__"yyandao1",
		"1"    : __DIR__"xcandao1",
		"2"    : __DIR__"zlandao1",
		"3"    : __DIR__"slandao1",
		"4"    : __DIR__"xxandao1",
		"5"    : __DIR__"wdandao1",
		"6"    : __DIR__"hsandao1",
		"7"    : __DIR__"bjandao1",
		"8"    : __DIR__"qzandao1",
		"9"    : __DIR__"xsandao1",
		"a"    : __DIR__"dlandao1",
		"b"    : __DIR__"fzandao1",
		"c"    : __DIR__"wxandao1",
		"f"    : __DIR__"cdandao1",
	]));
	set("item_desc",([ "map" : 
		"出口零：通往岳阳。\n"
		"出口一：通往小村。\n" +
		"出口二：通往竹林。\n" +
		"出口三：通往少林。\n" +
		"出口四：通往星宿。\n" +
		"出口五：通往武当。\n" +
		"出口六: 通往华山。\n" +
		"出口七：通往北京。\n" +
		"出口八：通往嘉兴。\n" +
		"出口九：通往雪山。\n" +
		"出口Ａ：通往大理。\n" +
		"出口Ｂ：通往福州。\n"
		"出口Ｃ：通往无锡。\n"
		"出口Ｆ：通往成都。\n"
	]));
	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", -20);
	setup();
}

void init()
{
	object ob = this_player();
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if (!myfam || myfam["family_name"] != "丐帮")
	{
		message_vision("\n粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
		ob->move("/d/gaibang/inhole");
		message("vision", "只听“乒”地一声，" + ob->query("name") + "从小门里飞了出来。\n", environment(ob), ob);
	}
}
