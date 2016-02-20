// gaoshou.c ½Ù·Ë
#include <ansi.h>
#include "init.h"
inherit NPC;
	string *xing=({"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ðí","ºÎ","ÂÀ","Ê©","ÕÅ","¿×","²Ü","ÑÏ","»ª","½ð","Îº","ÌÕ","½ª","ÆÝ","Ð»","×Þ","Ó÷","°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ð","ÞÉ","·¶","Åí","ÀÉ","Â³","Î¤","²ý","Âí","Ãç","·ï","»¨","·½","Óá","ÈÎ","Ô¬","Áø","Ûº","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ","ëø","Òó","ÂÞ","±Ï","ºÂ","Úù","°²","³£","ÀÖ","ÓÚ","Ê±","¸µ","Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","ÃÏ","Æ½","»Æ","ºÍ","ÄÂ","Ïô","Òü","Ò¦","ÉÛ"}); 
	string *id=({"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","zhu","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang","kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu","bai","shui","dou","zhang","yun","su","pan","ge","xi","fan","pen","lang","lu","wei","chang","ma","miao","feng","hua","fang","yu","ren","yuan","liu","feng","bao","shi","tang","fei","lian","cen","xue","lei","he","ni","tang","teng","yin","luo","bi","hao","wu","an","chang","le","yu","shi","fu","pi","bian","qi","kang","wu","yu","yuan","piao","gu","meng","ping","huang","he","mu","xiao","yin","yao","shao"}); 
	string *ming1=({"Ìì","µØ","Ðþ","»Æ","Óî","Öæ","ºé","»Ä","ÈÕ","ÔÂ","Ó¯","ê¾","³½","ËÞ","ÁÐ","º®","À´","Êî","Íù","Çï","¶¬","âÅ","³É","ÂÉ","Ñô","ÔÆ","ÌÚ","Óê","Â¶","Ëª","½ð","Éú","Àö","Ë®","Óñ","À¥","¸Ô","½£","¾Þ","ãÚ","Öé","Ò¹","¹â","Õä","ÖØ","º£","ºÓ","ÁÛ","Óð","Ïè","Áú","Ê¦","»ð","µÛ","Äñ","¹Ù","ÈË","»Ê","ÎÄ","ÉÑ","¹ú","ÌÕ","Ãñ","ÖÜ","·¢","Òó","ÌÀ","³¯","µÀ","´¹","¹°","Æ½","ÕÂ","°®","Óý","Àè","Ê×","³¼","·ü","±ö","Íõ","Ãù","·ï","Öñ","°×","¾Ô","»¯","²Ý","Ä¾"}); 
	string *ming2=({"Ìì","µØ","Ðþ","»Æ","Óî","Öæ","ºé","»Ä","ÈÕ","ÔÂ","Ó¯","ê¾","³½","ËÞ","ÁÐ","ÂÉ","Ñô","ÔÆ","ÌÚ","Óê","Â¶","Ëª","½ð","Éú","Àö","Ë®","Óñ","À¥","¸Ô","½£","¾Þ","ãÚ","Öé","Ò¹","¹â","Õä","ÖØ","º£","ºÓ","ÁÛ","Óð","Ïè","Áú","¹Ù","ÈË","»Ê","ÎÄ","ÉÑ","¹ú","ÌÕ","Ãñ","ÖÜ","·¢","Òó","ÌÀ","³¯","µÀ","´¹","¹°","Æ½","ÕÂ","°®","Óý","Àè","Ê×","³¼","·ü","±ö","³¤","ÐÅ","Æ÷","Ê«","¾°","ÐÐ","ÏÍ","¿Ë","Ê¥","µÂ","½¨","Ãû","Á¢","ÐÎ","¶Ë","±í","Õý","¿Õ","¹È","´«","Éù"}); 
	string *hhxm=({"É³Í¨Ìì","ºîÍ¨º£","ÉòÇà¸Õ","ÎâÇàÁÒ","ÂíÇàÐÛ","Ç®Çà½¡"}); 
	string *hhid=({"sha","hou","shen","wu","ma","qian"}); 
	string *hhtitle=({"»ÆºÓ°ï°ïÖ÷","»ÆºÓ°ïÏÈ·æ","»ÆºÓËÄ¹íÖ®Ò»","»ÆºÓËÄ¹íÖ®¶þ","»ÆºÓËÄ¹íÖ®Èý","»ÆºÓËÄ¹íÖ®ËÄ"});
	string *hhnick=({"¹íÃÅÁúÍõ","ÈýÍ·òÔ","¶Ï»êµ¶","×·ÃüÇ¹","¶áÆÇ±Þ","É¥ÃÅ¸«"}); 
	string *tyxm=({"åÐÒ£×Ó","³£³¤·ç","»¨½£Ó°","¸ÇÒ»Ãù"});
	string *tyid=({"xiaoyao","chang","hua","gai"});
	string *tytitle=({"Ì«ÔÀËÄÏÀÖ®Ò»","Ì«ÔÀËÄÏÀÖ®¶þ","Ì«ÔÀËÄÏÀÖ®Èý","Ì«ÔÀËÄÏÀÖ®ËÄ"});
	string *tynick=({HIM"ÑÌÏ¼ÉñÁú",HIG"Ë«ÕÆ¿ª±®",HIC"Á÷ÐÇ¸ÏÔÂ",HIB"°Ë²½¸Ïó¸¡¢Èü×¨Öî¡¢Ì¤Ñ©ÎÞºÛ¡¢¶À½ÅË®ÉÏ·É¡¢Ë«´Ì¸ÇÆßÊ¡"});
void create()
{
	int i, j;
	switch (random(10))
	{
		case 0:
			i = random(sizeof(tyxm));
			set_name(tyxm[i], ({tyid[i]}));
			set("title",HIG+tytitle[i]+NOR);
			set("nickname",tynick[i]+NOR);
			break;
		case 1:
			i = random(sizeof(hhxm));
			set_name(hhxm[i], ({hhid[i]}));
			set("title",HIY+hhtitle[i]+NOR);
			set("nickname",hhnick[i]+NOR);
			break;
		default:
			i = random(sizeof(xing));
			set_name(xing[i]+ming1[random(sizeof(ming1))]+ming2[random(sizeof(ming2))], ({id[i]}));
			set("title",HIY"»ÆºÓ°ïÌÃÖ÷"NOR);
			set("long","Ò»Î»±ëº·µÄ±±·½ºº×Ó£¬Ò»Éí»ÆºÓ°ïµÄºÚÒÂ¡£\n");
			break;
	}
	set("gender", "ÄÐÐÔ" );
	set("age", 30 + random(25) );
        set("max_qi",1200+random(300));
        set("max_jing",500+random(200));
	set("attitude", "heroism");
	set("str", 20 + random(11));	// ëöÁ¦
	set("per", 20 + random(11));	// ÈÝÃ²
	set("int", 20 + random(11));	// ÎòÐÔ
	set("con", 20 + random(11));	// ¸ù¹Ç
	set("dex", 100 + random(11)); 	// Éí·¨
	set("kar", 20 + random(11));	// ¸£Ôµ
	set("shen", -10);
	set("demogorgon",1);
	set("no_suck",1);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
   //   set_temp("apply/damage", 40);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge", 40);
	setup();
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	carry_object(__DIR__"obj/ycloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 2);
}

