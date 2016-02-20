// Room: /d/fuzhou/huangxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "黄巷");
	set("long", @LONG
晋永嘉年间(307—312)中原黄姓人家避乱入闽，落户在此，故称黄
巷。唐代黄璞返隐归居这里。黄巢军入福州，因闻黄璞的大名，命令兵
士“灭炬而过”。巷内历代多住儒林学士，人文荟萃。清代知府林文英，
榜眼林枝春、巡抚李馥、楹联大师梁章钜、进士陈寿棋、赵新等，都曾
居巷内。梁章钜五十八岁时，引疾归田，住的就是黄璞的旧居，他在宅
内建的小楼，取名黄楼，旁辟假山池馆，颇有江南园林风韵。
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie4",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
