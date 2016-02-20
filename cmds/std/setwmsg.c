// setwmsg.c
// SetWeaponMsg
//Creat by ZCooker 97.12.6
inherit F_CLEAN_UP;

#include <ansi.h>



int help();

int main(object me, string info)
{	
	if( !info ) return help();
	if( !(me->query("weapon/make")))
		return notify_fail("ÄãÃ»ÓÐ×ÔÖÆµÄ±øÆ÷£¡\n");
	return 0;
}

int help()
{
	write( @HELP
    Ö¸Áî¸ñÊ½£º£ó£å£ô£÷£í£ó£ç  £­£÷£ü£­£õ <¾ßÌåÃèÊö>¡£
    Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄãÎª×Ô¼ºµÄÎäÆ÷¼ÓÈë×°±¸ÒÔ¼°Ð¶ÏÂÊ±µÄÃèÊöÓïÑÔ¡£
    £­£÷£º½«ºóÐøÎÄ×Ö×÷Îª±øÆ÷×°±¸Ê±µÄÃèÊöÓïÑÔ¡£
    £­£õ£º½«ºóÐøÎÄ×Ö×÷ÎªÐ¶ÏÂ±øÆ÷Ê±µÄÃèÊöÓïÑÔ¡£
    ÔÚÃèÐ´ÖÐÊ¹ÓÃ$£Î´úÌæ×Ô¼º£¬Ê¹ÓÃ$£×£Å£Á£Ð£Ï£Î$´úÌæ±øÆ÷Ãû³Æ¡£×¢ÒâÈç
¹ûÔÚ±øÆ÷Ãû³Æºó»¹ÓÐÃèÐ´ÎÄ×ÖÄÇÃ´ÐèÒªÖØÐÂ¶¨ÒåÑÕÉ«£¬·ñÔò½«°´Ä¬ÐíÑÕÉ«´¦Àí¡£

    ÄãÈç¹ûÏ£ÍûÔÚÃèÊöÖÐÊ¹ÓÃ£Á£Î£Ó£ÉµÄ¿ØÖÆ×ÖÔª¸Ä±äÑÕÉ«£¬¿ÉÒÔÓÃÒÔÏÂµÄ¿Ø
ÖÆ×Ö´®£º£¨ÆäÖÐÏµÍ³×Ô¶¯»áÔÚ×Ö´®Î²¶Ë¼ÓÒ»¸ö $£Î£Ï£Ò$¡££©

        $£Â£Ì£Ë$£º[30mºÚÉ«[0m          
        $£Ò£Å£Ä$£º[31mºìÉ«[0m          $£È£É£Ò$£º[1;31mÁÁºìÉ«[0m
        $£Ç£Ò£Î$£º[32mÂÌÉ«[0m          $£È£É£Ç$£º[1;32mÁÁÂÌÉ«[0m
        $£Ù£Å£Ì$£º[33mÍÁ»ÆÉ«[0m        $£È£É£Ù$£º[1;33m»ÆÉ«[0m
        $£Â£Ì£Õ$£º[34mÉîÀ¶É«[0m        $£È£É£Â$£º[1;34mÀ¶É«[0m
        $£Í£Á£Ç$£º[35mÇ³×ÏÉ«[0m        $£È£É£Í$£º[1;35m·ÛºìÉ«[0m
        $£Ã£Ù£Î$£º[36mÀ¶ÂÌÉ«[0m        $£È£É£Ã$£º[1;36mÌìÇàÉ«[0m
        $£×£È£Ô$£º[37mÇ³»ÒÉ«[0m        $£È£É£×$£º[1;37m°×É«[0m
        $£Î£Ï£Ò$£º[0m»Ö¸´Õý³£ÑÕÉ«[0m

HELP
	);
	return 1;
}
