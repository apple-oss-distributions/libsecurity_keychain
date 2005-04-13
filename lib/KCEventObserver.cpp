/*
 * Copyright (c) 2000-2001,2003-2004 Apple Computer, Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 *
 * KCEventObserver.cpp -- OS X CF Observer for Keychain Events
 */

#include "KCEventObserver.h"

using namespace Security;

void Observer::consume (SecurityServer::NotificationDomain domain, SecurityServer::NotificationEvent event, const CssmData &data)
{
    secdebug("kcnotify", "Security::Observer::EventReceived got event %u", (unsigned int) event);

	// make a NameValueDictionary from the data we received
	NameValueDictionary nvd (data);
	Event (domain, event, nvd);
}



Observer::Observer (SecurityServer::NotificationDomain whichDomain, SecurityServer::NotificationMask whichEvents)
	: SecurityServer::EventListener(whichDomain, whichEvents)
{
}



Observer::~Observer ()
{
}