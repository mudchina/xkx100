// Room: /d/taishan/yitian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "一天门");
	set("long", @LONG
从岱宗坊上山大约走四里，便来到一天门。北面有一座天阶坊，过
了此坊便进入了登泰山的盘道。南面有一座更衣亭，士大夫们及其随从，
都会在这里换上轻便的服装，才继续登山。从一天门向北眺望，南天门
与十八盘在云雾明灭间或隐或现，登泰山的人到此已有观止之叹。附近
有一牌坊，嘉靖状元罗洪先题额(e) 并联(lian)，相传为「孔子过泰山
侧」的故事发生的地方。
LONG );
	set("exits", ([
		"southwest" : __DIR__"guandi",
		"northup"   : __DIR__"sanyibai",
		"southdown" : __DIR__"hongmen",
	]));
	set("item_desc", ([
		"e"    : "孔子登临处\n",
		"lian" : "秦王独步传千古  圣主遥临庆万年\n",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 560);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
