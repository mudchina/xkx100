// Room: /d/taishan/duzunju.c
// Last Modified by Winder on Aug. 25 2001
// Modified by Zeratul Jan 11 2001 ½­ºşÔÄÀúµÍÓÚ10000²»ÄÜ¼ûÃËÖ÷

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "¶À×ğ¾Ó");
	set("long", @LONG
ÕâÀïÊÇ´¦ÓÚá·¶¥ºóÉ½µÄÌìÏÂ´ó×ÚÊ¦¾ÓËù¡£ÇàÖñÔú¾ÍµÄ¾ÓËù£¬¶«Î÷Á½
Ãæ¿ª×Å´°»§£¬´°Íâ»¹ÊÇÇàÂÌµÄÖñÁÖºÍÁÖ¼äÍ¸½øµÄ°×ÔÆ¡£±±ÃæÇ½ÉÏÊÇÒ»·ù
ÖĞÌÃ£¬Í´¿ìÁÜÀìµØÈı¸ö´ó×Ö²İÊé£º[31;1m
                            ´ó
                            ×Ú
                            Ê¦[0m
    ´ó×ÚÊ¦ÔÚÕâÀï»á¼ûÌìÏÂµÄÓ¢ºÀ£¬Æ·ÆÀËûÃÇµÄÎä¹¦¡£Èç¹ûÄãÔ¸Òâ½ÓÊÜ
Æ·ÆÀ£¬¾ÍÎÊÎÊ´ó×ÚÊ¦£¬¿´ËûÊÇ·ñÔ¸Òâ³öÊÖ°É¡£²»¹ıÒªĞ¡ĞÄ£¬ÉúËÀÓëÌìÉñ
Î×Ê¦²»Ïà¸ÉµÄÅ¶¡£
LONG );
	set("exits", ([
		"out" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/dazongshi" : 1,
	]));
	set("coor/x", 410);
	set("coor/y", 650);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}

