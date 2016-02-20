//ROOM: /d/yanziwu/guifang.c

inherit ROOM;

void create()
{
	set("short", "靓闺房");
	set("long",@LONG
这里就是包三先生的宝贝乖女儿包不靓的闺房了。包小姐虽然年方
幼齿，可是摆弄起她那个在江湖上谁也不怕的爹来却是绝活。真让人相
信“一物降一物”的天理。不过也同时附带证明了另一条天理：“恶人
自有恶人磨”。
LONG );
	set("exits", ([
		"east": __DIR__"jinfeng",
	]));
	set("objects", ([
		__DIR__"npc/bao": 1,
	]));
	set("coor/x", 740);
	set("coor/y", -1550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}