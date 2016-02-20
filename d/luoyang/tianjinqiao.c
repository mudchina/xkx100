// Room: /d/luoyang/tianjinqiao.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "天津晓月");
	set("long",  @LONG
天津桥是用铁索连起无数大船而形成的一座浮桥。每当凌晨时分，
晓月还挂在天空，天津桥上的行人就熙熙攘攘车马如流了，无怪乎唐代
诗人列希夷写道“马声回合青云外，人影动摇绿波里”，真是写景如画。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" :  __DIR__"southgate",
		"south" :  __DIR__"road4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -35);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
