/*
 ###############################################################################
 #                                                                             #
 #    Copyright (C) 2011 OpenMEAP, Inc.                                        #
 #    Credits to Jonathan Schang & Robert Thacher                              #
 #                                                                             #
 #    Released under the GPLv3                                                 #
 #                                                                             #
 #    OpenMEAP is free software: you can redistribute it and/or modify         #
 #    it under the terms of the GNU General Public License as published by     #
 #    the Free Software Foundation, either version 3 of the License, or        #
 #    (at your option) any later version.                                      #
 #                                                                             #
 #    OpenMEAP is distributed in the hope that it will be useful,              #
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of           #
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
 #    GNU General Public License for more details.                             #
 #                                                                             #
 #    You should have received a copy of the GNU General Public License        #
 #    along with OpenMEAP.  If not, see <http://www.gnu.org/licenses/>.        #
 #                                                                             #
 ###############################################################################
 */

package com.openmeap.util;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

abstract public class ZipUtils {
	private ZipUtils() {}
	
	static public Long getUncompressedSize(ZipFile zipFile) {
		@SuppressWarnings("rawtypes")
		Enumeration e = zipFile.entries();
		Long uncompressedSize = 0L;
		while(e.hasMoreElements()) {
			ZipEntry zipEntry = (ZipEntry)e.nextElement();
			uncompressedSize += zipEntry.getSize();
		}
		return uncompressedSize;
	}
	
	static public void unzipFile(ZipFile zipFile, File destinationDir) throws IOException {
		int BUFFER = 1024;
		BufferedOutputStream dest = null;
		BufferedInputStream is = null;

		if( ! destinationDir.exists() ) {
			destinationDir.mkdir();
		}
		
		ZipEntry entry;
		@SuppressWarnings("rawtypes")
		Enumeration e = zipFile.entries();
		while(e.hasMoreElements()) {
			try {
				entry = (ZipEntry) e.nextElement();
				is = new BufferedInputStream(zipFile.getInputStream(entry));
				File file = new File(destinationDir,entry.getName());
				if( !file.exists() && entry.isDirectory() ) {
					file.mkdirs();
				} else {
					FileOutputStream fos = new FileOutputStream(file, false);
					dest = new BufferedOutputStream(fos, BUFFER);
					Utils.pipeInputStreamIntoOutputStream(is, fos);
				}
			} finally {
				if( dest!=null ) {
					dest.close();
				}
				if( is!=null ) {
					is.close();
				}
			}
		}
	}
}
