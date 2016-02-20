// Room: /beijing/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "回春堂药店");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的
几百个小抽屉里散发出来的。一位老者在柜台后站着。柜台上贴着一
张发黄的广告(guanggao)。柜台后面往西是一间内室(neishi)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
其他神药与老板面议。\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji2" : 1,
		CLASS_D("yunlong")+"/xutianchuan" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xichang1",
                "west" : __DIR__"neishi",   
	]));
//	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
