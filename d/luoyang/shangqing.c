// Room: /d/luoyang/shangqing.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "上清宫");
	set("long",  @LONG
上清宫位于邙山之巅翠云峰，相传这里为太上老君炼丹处。上清宫
规模宏伟，殿堂巍峨，门外有石狮石马。明代嘉靖十四年，道士张玄募
钱重建，以山高风大，改殿顶小瓦为大型釉瓦，屋脊置铁瓦，故称大殿
为铁瓦琉璃殿。历代文人墨客涉足山巅，南望伊洛平原，古都尽收眼底。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southeast" : __DIR__"mangshan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -510);
	set("coor/y", 60);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
