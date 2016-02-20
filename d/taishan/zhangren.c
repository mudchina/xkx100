// Room: /d/taishan/zhangren.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "丈人峰");
	set("long", @LONG
这里位于玉皇顶以西里许的地方，形状有如一个伛偻的老人。附近
有数块俊秀小石，故又有“老翁弄孙”之称。峰上有“天下第一山”、
“凌霄峻极”、“中天独立”、“东柱第一灵区”诸刻，并有乾隆诗刻
：“丈人五岳自青城，岱顶何来假借名。却是世人知此惯，谁因杜老句
详评。”
    靠西有黄华洞，因洞路极为危险，后人在进路处写上「回车岩」。
从这里往北走便是岱顶的北天门。
LONG );
	set("exits", ([
		"southeast" : __DIR__"yuhuang",
		"northup"   : __DIR__"beitian",
	]));
	set("objects",([
		__DIR__"npc/wei-shi1" : 2,
	]));
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 790);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
